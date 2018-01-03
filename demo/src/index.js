import React from 'react';
import {render} from 'reason-react-dom';

const App = () => (
  <h1>Hello, world</h1>
);

render(<App />, document.getElementById('root'));
