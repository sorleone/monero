mkdir -p ~/wallets
cd ../build/Linux/master/release/bin

./monero-wallet-cli --long-payment-id-support --daemon-port 28081 --trusted-daemon --generate-new-wallet ~/wallets/wallet_01.bin --restore-deterministic-wallet --electrum-seed="sequence atlas unveil summon pebbles tuesday beer rudely snake rockets different fuselage woven tagged bested dented vegan hover rapid fawns obvious muppet randomly seasons randomly" --password "" --log-file ~/wallets/wallet_01.log
