# Medipedia Token
## Symbol : MEP

## Steps to deploy smart contract and use the deployed token in EOS Blockchain

### Create Keys
Private key: "YOUR-PRIVATE-KEY"

Public key:  "YOUR-PUBLIC-KEY"

### Create Account

```
cleos create account eosio eosiomedipedia "YOUR-PUBLIC-KEY" "YOUR-PUBLIC-KEY"
```

```
cleos create account eosio user "YOUR-PUBLIC-KEY" "YOUR-PUBLIC-KEY"
```

### Deploy Contract

```
cleos set contract eosiomedipedia ../eosiomedipedia -p eosiomedipedia@active
```

### Get Hashcode of deployed Contract

```
cleos get code eosiomedipedia
```

### Create Token

```
cleos push action eosiomedipedia create '["eosiomedipedia","260000000.00 MEP"]' -p eosiomedipedia@active
```

### Issue Token

```
cleos push action eosiomedipedia issue '["eosiomedipedia","130000000.00 MEP","memo"]' -p eosiomedipedia@active
```


### Transfer Token

```
cleos push action eosiomedipedia transfer '["eosiomedipedia","user","30000000.00 MEP","memo"]' -p eosiomedipedia
```

### Check Balance

```
cleos get currency balance eosiomedipedia user
```
```
cleos get currency balance eosiomedipedia eosiomedipedia
```
```
cleos get currency stats eosiomedipedia MEP
```
