/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosiolib/asset.hpp>
#include <eosiolib/eosio.hpp>

#include <string>

namespace eosiosystem {
   class system_contract;
}

namespace medipedia {
    using std::string;

    class eosiomedipedia : public eosio::contract {
        public:
            eosiomedipedia( account_name self ):contract(self){}
            /// @abi action
            void create( account_name issuer,
                         eosio::asset        maximum_supply);
            /// @abi action
            void issue( account_name to, eosio::asset quantity, string memo );
            /// @abi action
            void transfer( account_name from,
                           account_name to,
                           eosio::asset        quantity,
                           string       memo );
            /// @abi action
            void close( account_name owner, eosio::symbol_type symbol );

            inline eosio::asset get_supply( eosio::symbol_name sym )const;

            inline eosio::asset get_balance( account_name owner, eosio::symbol_name sym )const;

        private:

            struct account {
                eosio::asset    balance;

                uint64_t primary_key()const { return balance.symbol.name(); }
            };

            struct currency_stats {
                eosio::asset          supply;
                eosio::asset          max_supply;
                account_name   issuer;

                uint64_t primary_key()const { return supply.symbol.name(); }
            };

            typedef eosio::multi_index<N(accounts), account> accounts;
            typedef eosio::multi_index<N(stat), currency_stats> stats;

            void sub_balance( account_name owner, eosio::asset value );
            void add_balance( account_name owner, eosio::asset value, account_name ram_payer );
        public:
            ///@abi table
            struct transfer_args {
               account_name  from;
               account_name  to;
               eosio::asset         quantity;
               string        memo;
            };
    };

    eosio::asset eosiomedipedia::get_supply( eosio::symbol_name sym )const
    {
        stats statstable( _self, sym );
        const auto& st = statstable.get( sym );
        return st.supply;
    }

    eosio::asset eosiomedipedia::get_balance( account_name owner, eosio::symbol_name sym )const
    {
        accounts accountstable( _self, owner );
        const auto& ac = accountstable.get( sym );
        return ac.balance;
    }
} /// namespace medipedia


