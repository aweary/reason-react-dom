type t;

/**
 * The problem with the "children" prop is that it's polymorphic and we
 * have no control over what the value might be. There's no way to encode
 * `typeof` checks with Bucklescript since the idea is that Reason should
 * type check at compile time not runtime.
 * 
 * It would be nice to have an attribute that lets you treat runtime type checking
 * as it was compile-time.
 * 
 * type primitive = 
 *  | [@bs.typeof "string"] String
 *  | [@bs.typeof "number"] Number
 *  | [@bs.typeof "object"] Object;
 * 
 * 
 * let log = (a: primitive) => {
 *   switch (a) {
       | String => "String!"
       | Number => "Number!"
       | Object => "Object!"
     }
 * }
 * 
 * Which would compile to:
 * 
 * function log(a) {
 *   switch (typeof a) {
       case 'string':
         return "String!"
       // And so on...
     }
 * }
 */
type dangerousInnerHTML = {
  .
  "__html": string
};
type props = {.
  /* This is poorly typed since it could be a string or number */
  "children": string,
  "dangerouslySetInnerHTML": dangerousInnerHTML
};
type update;
type root;
type nodeList;

[@bs.get_index] external getValueFromProps : (props, string) => 'a = "";