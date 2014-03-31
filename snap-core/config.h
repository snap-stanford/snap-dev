enum algo_t {ALGO_ONE, ALGO_TWO}; // Rok version, Pararth version
algo_t CONVERSION_ALGO = ALGO_TWO;

enum graph_t {LIVEJOURNAL, TWITTER};
graph_t GRAPH = LIVEJOURNAL;

char paths[2][500] = {
  "/dfs/ilfs2/0/ringo/benchmarks/soc-LiveJournal1.table",
  "/dfs/ilfs2/0/ringo/benchmarks/twitter_rv.table"
};

/********************************************************/

char sch[2][100] = {"static", "dynamic"};

enum sched_t {SCHEDULE_STATIC, SCHEDULE_DYNAMIC};

const int SCHED_DYNAMIC_CHUNK_SIZE = 10000;
const int SCHED_STATIC_CHUNK_SIZE = 10000;

// Constants for ALGO_ONE
const int HASH_TABLE_SIZE = 4850000; // Live Journal
//const int HASH_TABLE_SIZE = 41700000; // Twitter

sched_t SCHED_ADD_NODE = SCHEDULE_DYNAMIC;
int ADD_NODE_NUM_THREADS = 64;

sched_t SCHED_ALLOC_EDGE_LISTS = SCHEDULE_STATIC;
int ALLOC_EDGE_LISTS_NUM_THREADS = 1;

sched_t SCHED_POPULATE_EDGE_LISTS = SCHEDULE_DYNAMIC;
int POPULATE_EDGE_LISTS_NUM_THREADS = 64;

sched_t SCHED_SORT_EDGE_LISTS = SCHEDULE_STATIC;
int SORT_EDGE_LISTS_NUM_THREADS = 64;

// Constants for ALGO_TWO

