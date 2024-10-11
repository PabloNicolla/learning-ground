# Generic Component Prop

## Example

```ts
import React from 'react';

interface Props<T> {
  component: React.ComponentType<T>;
  componentProps: T;
}

const ComponentWrapper = <T extends {}>({ component: Component, componentProps }: Props<T>) => {
  return <Component {...componentProps} />;
};

// Usage Example
const Button: React.FC<{ label: string }> = ({ label }) => <button>{label}</button>;

const App = () => {
  return (
    <div>
      <ComponentWrapper component={Button} componentProps={{ label: 'Click me' }} />
    </div>
  );
};

export default App;
```

### Explanation_1

- `React.ComponentType<T>`: This type allows the component prop to be any React component that accepts props of type T.
- componentProps: T: The specific props to be passed to the component.
- `<T extends {}>`: This makes the component generic, meaning it can work with any prop structure defined by T.

### Key Points

- `React.ComponentType<T>` works for both functional and class components.
- You can pass any component as a prop, and TypeScript will ensure that the passed componentProps match the expected props of the component.

## Enforce that T implements X

```ts
const ComponentWrapper = <T extends { onClick: () => void }>({ component: Component, componentProps }: Props<T>) => {
  return <Component {...componentProps} />;
};
```

### Explanation_2

- `<T extends { onClick: () => void }>`:
  - It still accepts a generic component, but the component must prop must have attribute `onClick` of type `() => void`
