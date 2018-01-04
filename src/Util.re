type lodash;

[@bs.module "lodash-es/isNumber"] external isNumber : 'a => bool = "default";
[@bs.module "lodash-es/isString"] external isString : 'a => bool = "default";
[@bs.module "./JsUtils.js"] external typeof : 'a => string = "getTypeOf";