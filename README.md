
## build 

`cd src`

`eosio-cpp -I tic_tac_toe.hpp tic_tac_toe.cpp -abigen`

## test

```shell

# new game
cleost push action game11112222 create '{"challenger":"bob111222111", "host":"alice1111222"}' --permission alice1111222@active

# play game
cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"alice1111222", "row":0, "column":0}' --permission alice1111222@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"bob111222111", "row":1, "column":0}' --permission bob111222111@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"alice1111222", "row":0, "column":1}' --permission alice1111222@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"bob111222111", "row":1, "column":1}' --permission bob111222111@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"alice1111222", "row":0, "column":2}' --permission alice1111222@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"bob111222111", "row":1, "column":2}' --permission bob111222111@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"alice1111222", "row":0, "column":3}' --permission alice1111222@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"bob111222111", "row":1, "column":3}' --permission bob111222111@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"alice1111222", "row":0, "column":4}' --permission alice1111222@active

cleost push action game11112222 move '{"challenger":"bob111222111", "host":"alice1111222", "by":"bob111222111", "row":1, "column":4}' --permission bob111222111@active
```


```shell
# restart game
cleost push action game11112222 restart '{"challenger":"bob111222111", "host":"alice1111222", "by":"alice1111222"}' --permission alice1111222@active

# close game
cleost push action game11112222 close '{"challenger":"bob111222111", "host":"alice1111222"}' --permission alice1111222@active
```