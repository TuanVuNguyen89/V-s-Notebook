#define setit set<line>::iterator
struct line  {
    char type;
    double x;
    long long k, n;
};

long long sqr (long long x) {return x * x;}

bool operator < (line l1, line l2) {
    if (l1.type + l2.type > 0) return l1.x < l2.x;
    return l1.k > l2.k;
}

set <line> env;

bool hasPrev (setit it) {
    return it != env.begin();
}

bool hasNext (setit it) {
    return it != env.end() && next(it) != env.end();
}

double intersect (setit it1, setit it2) {
    return (double) (it1 -> n - it2 -> n) / (it2 -> k - it1 -> k);
}

void calcX (setit it) {
    if (hasPrev(it)) {
        line l = *it;
        l.x = intersect(prev(it), it);
        env.insert(env.erase(it), l);
    }
}

bool irrelevant (setit it) {
    if (hasNext(it) && next(it) -> n <= it -> n)return 1;
    return hasPrev(it) && hasNext(it) && intersect(prev(it), next(it)) <= intersect(prev(it), it);
}

void add(long long k, long long a) {
    setit it;
    it = env.lower_bound({0, 0, k, a});
    if(it != env.end() && it -> k == k) {
        if(it -> n <= a) return;
        else env.erase(it);
    }

    it = env.insert({0, 0, k, a}).first;
    if(irrelevant(it)) {
        env.erase(it);
        return;
    }

    while (hasPrev(it) && irrelevant(prev(it))) env.erase(prev(it));
    while (hasNext(it) && irrelevant(next(it))) env.erase(next(it));

    if (hasNext(it)) calcX(next(it));
    calcX(it);
}

long long query(long long x) {
    auto it = env.upper_bound((line){1, (double)x, 0, 0});
    it--;
    return it -> n + x * it -> k;
}
