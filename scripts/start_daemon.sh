cd ../build/Linux/master/release/bin

./monerod --regtest --fixed-difficulty=1 --p2p-bind-port 28080 --rpc-bind-port 28081 --no-igd --hide-my-port --log-level 1 --p2p-bind-ip 127.0.0.1 --log-file ~/wallets/node_01.log --data-dir ~/wallets/node_01 --zmq-rpc-bind-ip 127.0.0.1 --zmq-rpc-bind-port 28082 --offline
