# CAP Theorem a.k.a Brewers Theorem

1. C stands for Consistency
   1. consistency in CAP theorem is different from cosnistency in ACID
   2. In cap C means evvery recent read will have the recent written DATA
   3. In ACID C stands for My db goes from one constant state to another constant state
2. A stands for availability
   1. Every req recieves th non error response without the gauarentee of most recent write
   2. Whatever is the response send it to me
3. P stands for Partition tolerance
   1. The system continius to operate even some messages are dropped

## Erik Brewere

- any distributed db can always gauruntee both of these 3 thhings
- 2 of the following 3 garuantees Trillema
- If a db is distributed ince has to choose between **Availability & Consistency**
- No system is free from netwrok failures and has to be tolerated & this hold true in a wide netwrok
- In absence of network partition both **Availability & Consistency** can be satisfied.
- If a sysytem is Avaiable and Partiton then there is no scope for inconsistency
- Bascially we can when ever distribute over DB, we Can choose AP, or CP.
