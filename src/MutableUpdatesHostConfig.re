open Webapi.Dom;


type abstractT('t, 'p, 'i, 'ti, 'c, 'pl) = {
  .
  "commitUpdate": ('i, 'pl, 't, 'p, 'p, ReactFiber.t) => unit,
  "commitMount": ('i, 't, 'p, ReactFiber.t) => unit,
  "commitTextUpdate": ('ti, string, string) => unit,
  "resetTextContent": ('i) => unit,
  "appendChild": ('i, 'i) => unit,
  "appendChildToContainer": ('c, 'i) => unit,
  "insertBefore": ('i, 'i, 'i) => unit,
  "insertInContainerBefore": ('c, 'i, 'i) => unit,
  "removeChild": ('i, 'i) => unit,
  "removeChildFromContainer": ('c, 'i) => unit
};


type t = abstractT(
  string,
  ReactFiber.props,
  Element.t,
  Text.t,
  Element.t,
  Js.Array.t(ReactFiber.update)
);


let commitUpdate = (_instance, _updatePayload, _type, _oldProps, _newProps, _fiber) => {
  Js.log("commitUpdate");
 ()
};

let commitMount = (_instance, _type, _newProps, _fiber) => {
  Js.log("commitMount");
  ()
};

let commitTextUpdate = (textInstance, _oldText, newText) => {
  Js.log("commitTextUpdate");
  Text.setNodeValue(textInstance, Js.Null.return(newText))
};

let resetTextContent = (element) => {
  Js.log("resetTextContent");
  Element.setTextContent(element, "")
};

let appendChild = (parent, child) => {
  Js.log("appendChild");
  Element.appendChild(child, parent)
};

let appendChildToContainer = (container, child) => {
  Js.log("appendChildToContainer");
  Element.appendChild(child, container)
};

let insertBefore = (parentInstance, child, beforeChild) => {
  Js.log("insertBefore");
  ignore(Element.insertBefore(child, beforeChild, parentInstance));
};


let removeChild = (parentInstance, child) => {
  ignore(Element.removeChild(child, parentInstance));
};

let make : unit => t = () => {
  "commitUpdate": commitUpdate,
  "commitMount": commitMount,
  "commitTextUpdate": commitTextUpdate,
  "resetTextContent": resetTextContent,
  "appendChild": appendChild,
  "appendChildToContainer": appendChildToContainer,
  "insertBefore": insertBefore,
  "insertInContainerBefore": insertBefore,
  "removeChild": removeChild,
  "removeChildFromContainer": removeChild
};