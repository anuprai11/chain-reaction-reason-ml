/**
 * Created by anuprai on 28/07/18.
 */
 let myStyle = ReactDOMRe.Style.make(
    ~height="100%", 
    ~width="100%",
    ~border="1px solid red",
    ()
    );

let component = ReasonReact.statelessComponent("ChainReaction");
let make = _children => {
    ...component, 
    render: _self => <div style=myStyle> <Board dimension=16 numberOfPlayers=4/> </div>
};
