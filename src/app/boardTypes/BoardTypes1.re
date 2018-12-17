type action =
  | UserClick;

type box = {
  isFilled: bool,
  userId: int,
  numberOfBalls: int,
};

type user={
  userId:int,
  userColorCode:int,
};

type usersConfig = {
  userCount:int,
  users:array(user),
};
