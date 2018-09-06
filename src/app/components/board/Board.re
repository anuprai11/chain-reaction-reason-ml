let component = ReasonReact.reducerComponent("Board");

let myStyle = ReactDOMRe.Style.make(
    ~height="100%", 
    ~width="100%",
    ~border="1px solid black",
    ()
    );
    
type box={
    isFilled: bool,
    userId: int,
    numberOfBalls: int,
};

type state = {
  gameState: list(list(box)),
  chaceSequence:int,
};

/* let initialState = {
  gameState: ,
  chaceSequence:0,
}; */
let getGameStateRow(columnIndex, dimension){
    if(columnIndex === dimension){
        []
    }
    [{
        isFilled: false,
        userId: -1,
        numberOfBalls: 0,
    }].conacat(gameStateRow(columnIndex+1, dimension));
}

let getGameState = (rowIndex, dimension) => {
    if(rowIndex === dimension){
        getGameStateRow(dimension);
    }
}

let make = (dimension, ~numberOfPlayers, _children) => {
    ...component, 
    initialState: () => {
        let gameState:list(list(box)) = getGameState(dimension);
        
        {
            gameState,
            chaceSequence:0
        }
    },
    reducer: (_action, _state) => ReasonReact.NoUpdate,
    render: _self =>  {
        <div style=myStyle>
        <div>(ReasonReact.string("Welcome to Chain Reaction Version 1"))</div>
        </div>
    }
}   