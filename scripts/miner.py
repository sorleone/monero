# source: https://moneroexamples.github.io/python-json-rpc/

'''
Usage: python3 miner.py [blocks to mine] [wallet address] [port]
'''
import sys
import requests
import json

# execute an rpc request
def execute_rpc(inputs, port):
    return requests.post(
        "http://localhost:"+port+"/json_rpc", # node is running on port
        data=json.dumps(inputs),
        headers={'content-type': 'application/json'}) # standard json header

def main():
    if(len(sys.argv) < 3):
        print("please pass # of blocks, wallet address and port as arguments")
        exit()
    blocks = int(sys.argv[1])
    address = str(sys.argv[2])
    port = str(sys.argv[3])
    
    # procedure/method to call
    rpc_input_generateblocks = {
        "method": "generateblocks",
        "params": {
            "amount_of_blocks" : blocks,
            "reserve_size" : 20,
            "wallet_address": address
        }
    }

    # add standard rpc values
    rpc_input_generateblocks.update({"jsonrpc": "2.0", "id": "0"})

    # execute rpc call and print result
    print(execute_rpc(rpc_input_generateblocks, port).json())

if __name__ == "__main__":
    main()
