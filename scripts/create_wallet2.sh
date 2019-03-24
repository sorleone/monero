mkdir -p ~/wallets
cd ../build/Linux/master/release/bin

./monero-wallet-cli --long-payment-id-support --daemon-port 28081 --trusted-daemon --generate-new-wallet ~/wallets/wallet_02.bin --restore-deterministic-wallet --electrum-seed="deftly large tirade gumball android leech sidekick opened iguana voice gels focus poaching itches network espionage much jailed vaults winter oatmeal eleven science siren winter" --password "" --log-file ~/wallets/wallet_02.log
