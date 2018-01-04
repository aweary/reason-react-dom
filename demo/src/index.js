import React from 'react';
import {render} from 'reason-react-dom';

const App = () => (
  <div className="container">
    <h1 style="color: red">Hello, world!</h1>
  </div>
);

render(<App />, document.getElementById('root'));
