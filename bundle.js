'use strict';

Object.defineProperty(exports, '__esModule', { value: true });

function _interopDefault (ex) { return (ex && (typeof ex === 'object') && 'default' in ex) ? ex['default'] : ex; }

var ReactReconciler = _interopDefault(require('react-reconciler'));

function createRenderer(config) {
  return ReactReconciler(config);
}

function from_opt(x) {
  if (x) {
    return x[0];
  } else {
    return undefined;
  }
}


/* No side effect */

// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
function commitUpdate(_, _$1, _$2, _$3, _$4, _$5) {
  console.log("commitUpdate");
  return /* () */0;
}

function commitMount(_, _$1, _$2, _$3) {
  console.log("commitMount");
  return /* () */0;
}

function commitTextUpdate(textInstance, _, newText) {
  console.log("commitTextUpdate");
  textInstance.nodeValue = newText;
  return /* () */0;
}

function resetTextContent(element) {
  console.log("resetTextContent");
  element.textContent = "";
  return /* () */0;
}

function appendChild(parent, child) {
  console.log("appendChild");
  parent.appendChild(child);
  return /* () */0;
}

function appendChildToContainer(container, child) {
  console.log("appendChildToContainer");
  container.appendChild(child);
  return /* () */0;
}

function insertBefore(parentInstance, child, beforeChild) {
  console.log("insertBefore");
  parentInstance.insertBefore(child, beforeChild);
  return /* () */0;
}

function removeChild(parentInstance, child) {
  parentInstance.removeChild(child);
  return /* () */0;
}

function make() {
  return {
          commitUpdate: commitUpdate,
          commitMount: commitMount,
          commitTextUpdate: commitTextUpdate,
          resetTextContent: resetTextContent,
          appendChild: appendChild,
          appendChildToContainer: appendChildToContainer,
          insertBefore: insertBefore,
          insertInContainerBefore: insertBefore,
          removeChild: removeChild,
          removeChildFromContainer: removeChild
        };
}


/* No side effect */

// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
function getRootHostContext() {
  console.log("getRootHostContext");
  return "";
}

function getChildHostContext(_, _$1, _$2) {
  console.log("getChildHostContext");
  return "";
}

function getPublicInstance(instance) {
  console.log("getPublicInstance");
  return instance;
}

function createInstance(t, _, _$1, _$2, _$3) {
  console.log("createInstance");
  return document.createElement(t);
}

function appendInitialChild(parent, child) {
  console.log("appendInitialChild");
  parent.appendChild(child);
  return /* () */0;
}

function finalizeInitialChildren(_, _$1, _$2, _$3) {
  console.log("finalizeInitialChildren");
  return false;
}

function prepareUpdate(_, _$1, _$2, _$3, _$4, _$5) {
  console.log("Preparing update...");
  return from_opt(/* Some */[/* array */[]]);
}

function shouldSetTextContent(_, _$1) {
  return false;
}

function shouldDeprioritizeSubtree(_, _$1) {
  return false;
}

function createTextInstance(text, _, _$1, _$2) {
  return document.createTextNode(text);
}

function prepareForCommit() {
  return /* () */0;
}

function resetAfterCommit() {
  return /* () */0;
}

var config = {
  getRootHostContext: getRootHostContext,
  getChildHostContext: getChildHostContext,
  getPublicInstance: getPublicInstance,
  createInstance: createInstance,
  appendInitialChild: appendInitialChild,
  finalizeInitialChildren: finalizeInitialChildren,
  prepareUpdate: prepareUpdate,
  shouldSetTextContent: shouldSetTextContent,
  shouldDeprioritizeSubtree: shouldDeprioritizeSubtree,
  createTextInstance: createTextInstance,
  scheduleDeferredCallback: window.requestIdleCallback,
  cancelDeferredCallback: window.cancelIdleCallback,
  prepareForCommit: prepareForCommit,
  resetAfterCommit: resetAfterCommit,
  now: (function () {
      return Date.now();
    }),
  mutation: make(/* () */0),
  useSyncScheduling: true
};


/* config Not a pure module */

// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
var renderer = createRenderer(config);

var containerMap = new WeakMap();

function render(element, container) {
  console.log("RENDERING");
  var createContainer = renderer.createContainer;
  var updateContainer = renderer.updateContainer;
  var root;
  if (containerMap.has(container)) {
    root = containerMap.get(container);
  } else {
    var newRoot = createContainer(container, false, false);
    containerMap.set(container, newRoot);
    root = newRoot;
  }
  return updateContainer(element, root, null, (function () {
                return /* () */0;
              }));
}


/* renderer Not a pure module */

exports.renderer = renderer;
exports.containerMap = containerMap;
exports.render = render;
