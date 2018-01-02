open Webapi.Dom;

type t;


let renderer = ReactReconciler.create(HostConfig.config);

let render = (element, container: Element.t) => {
  let createContainer = renderer##createContainer;
  let updateContainer = renderer##updateContainer;
  let root = if (ContainerWeakMap.has(container)) {
    ContainerWeakMap.get(container)
  } else {
    [@bs] createContainer(container, Js.false_, Js.false_)
  };
  /* TODO call updateContainer with element */
};