\l json-rpc.k
para:`0:

para"register function sum: +/"
sum:+/
para""

para"global id counter"
id:0
para""

para"client asks"
ask:{req["sum";id+:1;2 3 4]}
para""

para"create message"
m:`j@r:!/+ask[]
para@m
para""

r"id"

para"answer:"
m:`j@!/+recv@m
para@m
