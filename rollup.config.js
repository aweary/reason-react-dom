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
      // non-CommonJS modules will be ignored, but you can also
      // specifically include/exclude files
      include: ["node_modules/**", "src/**"], // Default: undefined
      // search for files other than .js files (must already
      // be transpiled by a previous plugin!)
      extensions: [".js"], // Default: [ '.js' ]
      // if true then uses of `global` won't be dealt with by this plugin
      // ignoreGlobal: false, // Default: false
      // if false then skip sourceMap generation for CommonJS modules
      // sourceMap: false, // Default: true
      // explicitly specify unresolvable named exports
      // (see below for more details)
      // namedExports: { "./module.js": ["foo", "bar"] }, // Default: undefined

      // sometimes you have to leave require statements
      // unconverted. Pass an array containing the IDs
      // or a `id => boolean` function. Only use this
      // option if you know what you're doing!
      // ignore: ["conditional-runtime-dependency"]
    })
    /*closure({ env: 'CUSTOM' })*/
  ]
};
