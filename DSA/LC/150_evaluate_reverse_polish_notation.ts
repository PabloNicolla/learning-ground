function evalRPN(tokens: string[]): number {
  let operands: number[] = [];
  let operators: string[] = [];

  for (let c of tokens) {
    if (["+", "-", "*", "/"].indexOf(c) != -1) {
      operators.push(c);
    } else {
      operands.push(Number(c));
    }

    if (operands.length >= 2 && operators.length >= 1) {
      const operator = operators[0];
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

// npm install -g ts-node
// ts-node filename.ts

// npm install -g typescript
// tsc yourfile.ts

// tsc --project tsconfig.json

export {};
