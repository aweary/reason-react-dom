open Webapi.Dom;
open ReactFiber;


[@bs.set_index] external setStyleProperty : (CssStyleDeclaration.t, string, string) => unit = "";

let setStyle = (element, styles: style) => {
  let element = Element.unsafeAsHtmlElement(element);
  let elementStyle = HtmlElement.style(element);
  Js.Obj.keys(styleAsObj(styles)) |> Js.Array.forEach((key) => {
    let value = getValueFromStyle(styles, key);
    Js.log("Setting " ++ key ++ " to " ++ value);
    setStyleProperty(elementStyle, key, value);
    /* CssStyleDeclaration.setProperty(key, value, "", elementStyle); */
  });
};