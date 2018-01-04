/* type t;
let renderer: ReasonReactReconciler.ReactReconciler.t;
let containerMap:
  ReasonReactReconciler.WeakMap.t
  (Webapi.Dom.Element.t,  ReasonReactReconciler.ReactFiber.root); */
let render:
  (ReasonReactReconciler.ReactFiber.nodeList, Webapi.Dom.Element.t) =>
  ReasonReactReconciler.ReactReconciler.expirationTime;