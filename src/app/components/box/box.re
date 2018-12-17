open BoardTypes1;

let component = ReasonReact.statelessComponent("Box");

let make = (~item:box, ~boxStyles,_children) => {
    ...component, 
    render: _self => <span style=boxStyles> (ReasonReact.string(string_of_int(item.numberOfBalls))) </span>
};