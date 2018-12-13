type action =
  | UserClick;

type box = {
  isFilled: bool,
  userId: int,
  numberOfBalls: int,
};

type state = {
  gameState: array(array(box)),
  chaceSequence: int,
};

let component = ReasonReact.reducerComponent("Board");

let rec getGameStateRow = (columnIndex, dimension) =>
  columnIndex == dimension ?
    [||] :
    Array.append(
      [|{isFilled: false, userId: (-1), numberOfBalls: 0}|],
      getGameStateRow(columnIndex + 1, dimension),
    );

let rec getGameState = (rowIndex, dimension) =>
  rowIndex == dimension ?
    [||] : Array.append([|getGameStateRow(0, dimension)|], getGameState(rowIndex + 1, dimension));

let initialState = (dimension: int, ()) => {
  let gameState: array(array(box)) = getGameState(0, dimension);
  {gameState, chaceSequence: 0};
};

let myStyle = ReactDOMRe.Style.make(~height="100%", ~width="100%", ~border="1px solid black", ());

let make = (~dimension, _children) => {
  ...component,
  initialState: initialState(dimension),
  reducer: (_action: action, _state: state) => ReasonReact.NoUpdate,
  render: _self =>
    <div style=myStyle>
      <div>
        (Array.map(_self.state.gameState, (boxItem, index) => Array.map(boxItem, () => ReasonReact.string("Box"))))
      </div>
    </div>,
};
