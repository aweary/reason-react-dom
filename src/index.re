open Webapi.Dom;

type t;

let renderer = ReactReconciler.create(HostConfig.config);

let containerMap: WeakMap.t(Element.t, ReactFiber.root) = WeakMap.make();

let render = (element: ReactFiber.nodeList, container: Element.t) => {
  Js.log("RENDERING");
  let createContainer = renderer##createContainer;
  let updateContainer = renderer##updateContainer;
  let root =
    if (container |> WeakMap.has(containerMap) |> Js.to_bool) {
      WeakMap.get(containerMap, container)
    } else {
      let newRoot = [@bs] createContainer(container, Js.false_, Js.false_);
      WeakMap.set(containerMap, container, newRoot);
      newRoot
    };
  [@bs] updateContainer(element, root, Js.Nullable.null, () => ());
  /* TODO call updateContainer with element */
};