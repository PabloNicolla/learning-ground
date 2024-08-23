#include <iostream>
#include <sstream>
#include <variant>
#include <vector>
#include <map>
#include <string>
#include <cctype>
#include <stdexcept>

// Forward declaration of the struct to use it recursively
struct JsonValue;

// Define a variant type to hold different JSON types
using JsonVariant = std::variant<std::nullptr_t, bool, double, std::string,
                                 std::vector<JsonValue>, std::map<std::string, JsonValue>>;

// Struct to represent a JSON value
struct JsonValue
{
  JsonVariant value;

  // Constructors for different types
  JsonValue() : value(nullptr) {} // for null
  JsonValue(bool b) : value(b) {}
  JsonValue(double d) : value(d) {}
  JsonValue(const std::string &s) : value(s) {}
  JsonValue(const char *s) : value(std::string(s)) {}
  JsonValue(const std::vector<JsonValue> &arr) : value(arr) {}
  JsonValue(const std::map<std::string, JsonValue> &obj) : value(obj) {}

  // Helper functions to access the value
  bool isNull() const { return std::holds_alternative<std::nullptr_t>(value); }
  bool isBool() const { return std::holds_alternative<bool>(value); }
  bool isNumber() const { return std::holds_alternative<double>(value); }
  bool isString() const { return std::holds_alternative<std::string>(value); }
  bool isArray() const { return std::holds_alternative<std::vector<JsonValue>>(value); }
  bool isObject() const { return std::holds_alternative<std::map<std::string, JsonValue>>(value); }

  // Accessors
  bool getBool() const { return std::get<bool>(value); }
  double getNumber() const { return std::get<double>(value); }
  const std::string &getString() const { return std::get<std::string>(value); }
  const std::vector<JsonValue> &getArray() const { return std::get<std::vector<JsonValue>>(value); }
  const std::map<std::string, JsonValue> &getObject() const { return std::get<std::map<std::string, JsonValue>>(value); }
};

// JSON Parser Class
class Json
{
public:
  static JsonValue parse(const std::string &str)
  {
    std::istringstream iss(str);
    return parseValue(iss);
  }

private:
  static void skipWhitespace(std::istringstream &iss)
  {
    while (iss && std::isspace(iss.peek()))
    {
      iss.get();
    }
  }

  static JsonValue parseValue(std::istringstream &iss)
  {
    skipWhitespace(iss);

    char c = iss.peek();
    if (c == '"')
    {
      return parseString(iss);
    }
    else if (c == '{')
    {
      return parseObject(iss);
    }
    else if (c == '[')
    {
      return parseArray(iss);
    }
    else if (std::isdigit(c) || c == '-')
    {
      return parseNumber(iss);
    }
    else if (c == 't' || c == 'f')
    {
      return parseBoolean(iss);
    }
    else if (c == 'n')
    {
      return parseNull(iss);
    }

    throw std::runtime_error("Unexpected character in JSON input");
  }

  static JsonValue parseString(std::istringstream &iss)
  {
    std::string result;
    char c;
    iss.get(); // Skip the opening quote

    while (iss.get(c))
    {
      if (c == '"')
      {
        break;
      }
      if (c == '\\')
      { // Handle escape sequences
        if (iss.get(c))
        {
          switch (c)
          {
          case '"':
            result += '"';
            break;
          case '\\':
            result += '\\';
            break;
          case '/':
            result += '/';
            break;
          case 'b':
            result += '\b';
            break;
          case 'f':
            result += '\f';
            break;
          case 'n':
            result += '\n';
            break;
          case 'r':
            result += '\r';
            break;
          case 't':
            result += '\t';
            break;
          default:
            throw std::runtime_error("Invalid escape sequence");
          }
        }
      }
      else
      {
        result += c;
      }
    }
    return JsonValue(result);
  }

  static JsonValue parseNumber(std::istringstream &iss)
  {
    double number;
    iss >> number;
    return JsonValue(number);
  }

  static JsonValue parseBoolean(std::istringstream &iss)
  {
    std::string token;
    iss >> token;

    if (token.back() == ',')
    {
      token.pop_back();
    }

    if (token == "true")
    {
      return JsonValue(true);
    }
    else if (token == "false")
    {
      return JsonValue(false);
    }
    throw std::runtime_error("Invalid boolean value");
  }

  static JsonValue parseNull(std::istringstream &iss)
  {
    std::string token;
    iss >> token;

    if (token.back() == ',')
    {
      token.pop_back();
    }

    if (token == "null")
    {
      return JsonValue();
    }
    throw std::runtime_error("Invalid null value");
  }

  static JsonValue parseArray(std::istringstream &iss)
  {
    std::vector<JsonValue> elements;
    iss.get(); // Skip the opening '['
    skipWhitespace(iss);

    while (iss.peek() != ']')
    {
      elements.push_back(parseValue(iss));
      skipWhitespace(iss);
      if (iss.peek() == ',')
      {
        iss.get(); // Skip the comma
        skipWhitespace(iss);
      }
    }
    iss.get(); // Skip the closing ']'
    return JsonValue(elements);
  }

  static JsonValue parseObject(std::istringstream &iss)
  {
    std::map<std::string, JsonValue> object;
    iss.get(); // Skip the opening '{'
    skipWhitespace(iss);

    while (iss.peek() != '}')
    {
      std::string key = parseString(iss).getString();
      skipWhitespace(iss);

      if (iss.get() != ':')
      { // Expect a colon
        throw std::runtime_error("Expected ':' after key in JSON object");
      }

      JsonValue value = parseValue(iss);
      object[key] = value;
      skipWhitespace(iss);

      if (iss.peek() == ',')
      {
        iss.get(); // Skip the comma
        skipWhitespace(iss);
      }
    }
    iss.get(); // Skip the closing '}'
    return JsonValue(object);
  }
};

int main()
{
  /*
  R"" is used to define a raw string literal.
  Raw string literals allow you to include characters that would otherwise need to be escaped in a regular string literal.
  */
  std::string jsonString = R"({
    "name": "John",
    "age": 30,
    "isStudent": false,
    "grades": [85.5, 90.3],
    "address": {"city": "New York", "zip": "10001"},
    "nullValue": null
  })";

  JsonValue jsonValue = Json::parse(jsonString);

  if (jsonValue.isObject())
  {
    const auto &obj = jsonValue.getObject();
    std::cout << "Name: " << obj.at("name").getString() << "\n";
    std::cout << "Age: " << obj.at("age").getNumber() << "\n";
    std::cout << "City: " << obj.at("address").getObject().at("city").getString() << "\n";
  }

  return 0;
}