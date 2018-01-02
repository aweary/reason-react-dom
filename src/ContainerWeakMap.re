open Webapi.Dom;

module WeakMap = {
  type t('key, 'value);
  [@bs.new] external make : unit => t('key, 'value) = "WeakMap";
  /* Right now we rely on a `has` check to account for entries that dont exist in
     the WeakMap. Really, get should return option('value) */
  [@bs.send] external get : t('key, 'value) => 'key => 'value = "get";
  [@bs.send] external set : t('key, 'value) => 'key => 'value => unit = "set";
  [@bs.send] external has : t('key, 'value) => 'key => Js.boolean = "has";
  [@bs.send] external remove : t('key, 'value) => 'key => unit = "remove";
};

let map : WeakMap.t(Element.t, ReactFiber.root) = WeakMap.make();

let get = (container) => {
  WeakMap.get(map, container)
};

let set = (container, root) => {
  WeakMap.set(map, container, root)
};

let remove = (container) => {
  WeakMap.remove(map, container)
};

let has = (container) => {
  Js.to_bool(WeakMap.has(map, container))
};