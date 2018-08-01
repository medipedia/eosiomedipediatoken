# Medipedia Token
## Symbol : MEP

##Steps to deploy and use the deployed token

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
