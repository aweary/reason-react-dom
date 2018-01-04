import closure from "rollup-plugin-closure-compiler-js";
import resolve from "rollup-plugin-node-resolve";
import commonjs from "rollup-plugin-commonjs";

export default {
  input: "src/index.bs.js",
  output: {
    file: "bundle.js",
    format: "cjs"
  },
  name: "ReactDOM",
  external: ["react-reconciler"],
  plugins: [
    resolve({ modules: true, jsnext: true, main: true, browser: true }),
    commonjs({
      include: ["node_modules/**"],
      exclude: ['node_modules/lodash-es/**'],
      extensions: [".js"],
    })
    // closure({ env: 'CUSTOM', externs: ['react-reconciler'] })
  ]
};
