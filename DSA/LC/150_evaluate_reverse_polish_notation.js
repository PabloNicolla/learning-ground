"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
function evalRPN(tokens) {
  var operands = [];
  var operators = [];
  for (var _i = 0, tokens_1 = tokens; _i < tokens_1.length; _i++) {
    var c = tokens_1[_i];
    if (["+", "-", "*", "/"].indexOf(c) != -1) {
      operators.push(c);
    } else {
      operands.push(Number(c));
    }
    if (operands.length >= 2 && operators.length >= 1) {
      var operator = operators[0];
      switch (operator) {
        case "+":
          operands[operands.length - 2] = operands[operands.length - 2] + operands[operands.length - 1];
          break;
        case "-":
          operands[operands.length - 2] = operands[operands.length - 2] - operands[operands.length - 1];
          break;
        case "*":
          operands[operands.length - 2] = operands[operands.length - 2] * operands[operands.length - 1];
          break;
        case "/":
          operands[operands.length - 2] = Math.trunc(operands[operands.length - 2] / operands[operands.length - 1]);
          operands[operands.length - 2] = operands[operands.length - 2] == -0 ? 0 : operands[operands.length - 2];
          break;
        default:
          break;
      }
      operands.pop();
      operators.shift();
    }
  }
  return operands[0];
}
console.log(evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]));
