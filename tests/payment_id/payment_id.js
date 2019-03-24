// transfer 46HZen5tbbPZiLn66S3Qzv8QfmtcwkdXgM5cWGsXAPxoQeMQ79md51PLPCijvzk1iHbuHi91pws5B7iajTX9KTtJ4aFuHcv 1 c8ac64e1363816a4334e0897c6e835e3f26fe5ab5a3164d85e800000000000ff
// monerod print_tx <TXID> +json

const encrypted = require('./encrypted.json');
const unencrypted = require('./unencrypted.json');

const payment_id = 'c8ac64e1363816a4334e0897c6e835e3f26fe5ab5a3164d85e800000000000ff';
const encrypted_extra = Buffer.from(encrypted.extra).toString('hex');
const unencrypted_extra = Buffer.from(unencrypted.extra).toString('hex');

console.log(encrypted_extra, encrypted_extra.includes(payment_id));
console.log(unencrypted_extra, unencrypted_extra.includes(payment_id));
