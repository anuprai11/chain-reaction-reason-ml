// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Board");

function getGameStateRow(columnIndex, dimension) {
  var match = columnIndex === dimension;
  if (match) {
    return /* array */[];
  } else {
    return $$Array.append(/* array */[/* record */[
                  /* isFilled */false,
                  /* userId */-1,
                  /* numberOfBalls */0
                ]], getGameStateRow(columnIndex + 1 | 0, dimension));
  }
}

function getGameState(rowIndex, dimension) {
  var match = rowIndex === dimension;
  if (match) {
    return /* array */[];
  } else {
    return $$Array.append(/* array */[getGameStateRow(0, dimension)], getGameState(rowIndex + 1 | 0, dimension));
  }
}

function initialState(dimension, _) {
  var gameState = getGameState(0, dimension);
  return /* record */[
          /* gameState */gameState,
          /* chaceSequence */0
        ];
}

var myStyle = {
  border: "1px solid black",
  height: "100%",
  width: "100%"
};

function make(dimension, _) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function () {
              return React.createElement("div", {
                          style: myStyle
                        }, React.createElement("div", undefined, "Welcome to Chain Reaction Version 1"));
            }),
          /* initialState */(function (param) {
              return initialState(dimension, param);
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (_, _$1) {
              return /* NoUpdate */0;
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.getGameStateRow = getGameStateRow;
exports.getGameState = getGameState;
exports.initialState = initialState;
exports.myStyle = myStyle;
exports.make = make;
/* component Not a pure module */
