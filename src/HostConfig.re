open Webapi.Dom;

type deadline = {. "timeRemaining": unit => int};
type deferredCallbackOptions = {. "timeout": int};
/* Right now all of these types are parametized, since that's how
   it's defined in ReactFiberReconciler. These will be filled in with concrete
   types as the implementation is developed */
/* @TODO use [@bs.deriving jsConverter] */
type abstractT('t, 'p, 'i, 'ti, 'hi, 'pi, 'c, 'cc, 'cx, 'pl) = {
  .
  "getRootHostContext": 'c => 'cx,
  "getChildHostContext": ('cx, 't, 'c) => 'cx,
  /* Need to declare an actual instance type that can be 'i or 'ti */
  "getPublicInstance": 'i => 'pi,
  "createInstance": ('t, 'p, 'c, 'cx, ReactFiber.t) => 'i,
  "appendInitialChild": ('i, 'i) => unit,
  "finalizeInitialChildren": ('i, 't, 'p, 'c) => Js.boolean,
  "prepareUpdate": ('i, 't, 'p, 'p, 'c, 'cx) => Js.Nullable.t('pl),
  "shouldSetTextContent": ('t, 'p) => Js.boolean,
  "shouldDeprioritizeSubtree": ('t, 'p) => Js.boolean,
  "createTextInstance": (string, 'c, 'cx, ReactFiber.t) => 'ti,
  "scheduleDeferredCallback": (deadline => unit, option(deferredCallbackOptions)) => float,
  "cancelDeferredCallback": float => unit,
  "prepareForCommit": unit => unit,
  "resetAfterCommit": unit => unit,
  "now": unit => float,
  "mutation": MutableUpdatesHostConfig.abstractT('t, 'p, 'i, 'ti, 'c, 'pl)
  /*
   Add these later if need be:
   "useSyncScheduling": any,
   "hydration": any,
   "persistence": any
   */
};
/* These will be defined later. The DOM types will come from bs-web-api */
type element;
type text = string;
type instance =
  | Element
  | Text;
type hostContext = string;
/* TODO: we don't need the abstract type `t` once this is well-defined */
type t =
  abstractT(
     /* T: Component Type */
    string,
    /* P: Props */
    ReactFiber.props, 
    /* I: Component Instance */
    Element.t,
    /* TI: Component Text Insptance */
    Text.t,
    /* HI: Hydration Instance */
    Element.t,
    /* PI: Public Instance */
    Element.t,
    /* C: Container instance */
    Element.t,
    /* CC: Child Container Instance */
    Element.t,
    /* CX: Host Context */
    hostContext,
    /* PL: Prepare Update Result */
    Js.Array.t(ReactFiber.update)
  );

/* We don't utilize host context at all right now, so 
   just return an empty string */
let getRootHostContext = (_context) => {
  ""
};

let getChildHostContext = (_type, _props, _container) => {
  ""
};

let getPublicInstance = (instance) => {
  instance
};

let createInstance = (t, _props, _container, _context, _fiber) => {
  document |> Document.createElement(t)
};

let appendInitialChild = (parent: Element.t, child: Element.t) => {
  parent |> Element.appendChild(child)
};

let finalizeInitialChildren = (_element, _type, _props, _inst) => {
  Js.false_
};

let prepareUpdate = (_inst, _type, _oldProps, _newProps, _conatiner, _context) => {
  Js.Nullable.from_opt(Some([||]))
};

let shouldSetTextContent = (_elementType, _props) => {
  Js.false_
};
let shouldDeprioritizeSubtree = (_type, _props) => {
  Js.false_
};

let createTextInstance = (text, _instance, _context, _fiber) => {
  document |> Document.createTextNode(text)
};

let scheduleDeferredCallback = (_callback, _options) => {
  Js.Date.now()
};

let cancelDeferredCallback = (_id) => {
  ()
};

let prepareForCommit = () => ();
let resetAfterCommit = () => ();



let config : t = {
  "getRootHostContext": getRootHostContext,
  "getChildHostContext": getChildHostContext,
  "getPublicInstance": getPublicInstance,
  "createInstance": createInstance,
  "appendInitialChild": appendInitialChild,
  "finalizeInitialChildren": finalizeInitialChildren,
  "prepareUpdate": prepareUpdate,
  "shouldSetTextContent": shouldSetTextContent,
  "shouldDeprioritizeSubtree": shouldDeprioritizeSubtree,
  "createTextInstance": createTextInstance,
  "scheduleDeferredCallback": scheduleDeferredCallback,
  "cancelDeferredCallback": cancelDeferredCallback,
  "prepareForCommit": prepareForCommit,
  "resetAfterCommit": resetAfterCommit,
  "now": Js.Date.now,
  "mutation": MutableUpdatesHostConfig.make()
};