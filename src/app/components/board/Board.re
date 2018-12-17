open BoardTypes1;

type state = {
  gameState: array(array(box)),
  chaceSequence: int,
  gameUsersConfig:usersConfig,
};

let colorPallet = [|
  "black",
  "red",
  "green",
  "blue",
  "yellow",
|];

let dummyUser : user = {
  userId:-1,
  userColorCode:-1,  
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
  let gameUsersConfig: usersConfig = {
    userCount:4,
    users:[|{
      userId:1,
      userColorCode:1,
    },{
      userId:2,
      userColorCode:2,
    },{
      userId:3,
      userColorCode:3,
    },{
      userId:4,
      userColorCode:4,
    }|],
  };
  {
    gameState:gameState,
    chaceSequence: 0, 
    gameUsersConfig:gameUsersConfig
    };
};

let myStyle = ReactDOMRe.Style.make(~height="100%", ~width="100%", ~border="1px solid black", ());

let getBoxStyles = (color) => ReactDOMRe.Style.make(~backgroundColor=color,~border="1px solid red", ());

let getColorForBalls = (userId:int,userConfig:usersConfig) => {
    let user= userId === -1 ? dummyUser :  userConfig.users[userId];
    let colorCode = user.userColorCode;
    switch(colorCode){
      | 1 =>colorPallet[colorCode]
      | 2 =>colorPallet[colorCode]
      | 3 =>colorPallet[colorCode]
      | 4 =>colorPallet[colorCode]
      | _=>"black"
    }
};

let make = (~dimension, _children) => {
  ...component,
  initialState: initialState(dimension),
  reducer: (_action: action, _state: state) => ReasonReact.NoUpdate,
  render: _self =>
    <div style=myStyle>
      <div>
        (
          ReasonReact.array(Array.map((boxItemArr: array(box)) => 
          <div>(ReasonReact.array(Array.map((boxItem:box) =>  {
              let color = getColorForBalls(boxItem.userId, _self.state.gameUsersConfig);
              <Box 
                item=boxItem
                boxStyles=(getBoxStyles(color)) 
              />
            })(boxItemArr)))</div>
          )(_self.state.gameState))
        )
      </div>
    </div>,
};
