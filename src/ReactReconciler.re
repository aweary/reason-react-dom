open Webapi.Dom;

type callback = unit => unit;

type expirationTime = float;

type container;

type reconciler('c /*, 'i, 'ti */) = {
  .
  "createContainer": [@bs] ('c, Js.boolean, Js.boolean) => ReactFiber.root,
  "updateContainer":
    (ReactFiber.nodeList, ReactFiber.root, ReactFiber.t, callback) => expirationTime,
  "updateContainerAtExpirationTime":
    (ReactFiber.nodeList, ReactFiber.root, ReactFiber.t, expirationTime, callback) =>
    expirationTime,
  "flushRoot": (ReactFiber.root, expirationTime) => unit,
  "requestWork": (ReactFiber.root, expirationTime) => unit,
  "batchedUpdates": callback => unit,
  "unbatchedUpdates": callback => unit,
  "flushSync": callback => unit,
  "deferredUpdates": callback => unit
  /*
   "injectDevTools": TODO,
   "computeUniqueAsyncExpiration": TODO
   */
};

type t = reconciler(Element.t);
type createReconciler = [@bs] HostConfig.t => t;

[@bs.module "./ReactReconcilerEntry.js"] external create : HostConfig.t => t = "createRenderer";