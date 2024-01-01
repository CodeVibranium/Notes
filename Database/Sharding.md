# Sharding

- Sharding is process of diving on big db into multiple smaller db where each db is speareated in a wide area network and has some part of data (partioned data)
- This is done to horizontally scale the database to serve reads & writes
- By sharding, we improve scalability, performance and fault tolerance
- Sharding involves splitting a database into smaller chunks based on certain criteria.
- For instance, a database with user profiles might be sharded based on user IDs, so all profiles with IDs between 1 and 10,000 might be on one shard, while those with IDs between 10,001 and 20,000 might be on another.

## Shared Key

- it used to determine how data is distributed over shards
- Choosing an appropriate shard key is crucial, as it affects the system's performance and scalability.
