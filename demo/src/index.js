import React from 'react';
import {render} from 'reason-react-dom';
import './index.css';

const App = () => (
  <div className="container">
    <h1 onClick={e => {console.log('clicked!')}} style={{ color: 'red', fontSize: '80px' }}>Hello, world!</h1>
  </div>
);

render(<App />, document.getElementById('root'));
