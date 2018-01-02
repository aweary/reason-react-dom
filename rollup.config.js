import closure from 'rollup-plugin-closure-compiler-js';

export default {
  input: "src/index.bs.js",
  output: {
    file: 'bundle.js',
    format: 'umd'
  },
  name: 'ReactDOM',
  external: ['react-reconciler', 'bs-platform/**/*.js'],
  plugins: [/*closure({ env: 'CUSTOM' })*/]
}