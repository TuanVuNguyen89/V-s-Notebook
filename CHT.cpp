struct Line {
    long long a, b;

    Line(long long a, long long b) {
        this->a = a; this->b = b;
    }
};

deque <Line> line;
bool bad(Line l1, Line l2, Line l3) {
    return (double) (l3.b - l1.b) / (l1.a - l3.a) <= (double) (l2.b - l1.b) / (l1.a - l2.a);
}

long long eval(Line tmp, long long x) {
    return tmp.a * x + tmp.b;
}

void add(Line x) {
    while (line.size() >= 2 && bad(line[line.size() - 2], line.back(), x)) line.pop_back();
    line.push_back(x);
}

long long get(long long x) {
    while (line.size() >= 2 && eval(line.front(), x) >= eval(line[1], x)) line.pop_front();
    return eval(line.front(), x);
}
