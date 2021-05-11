
class foo{
    public:
        foo():_x{0},_y{0}{};
        foo(const double x, const double y):_x{x},_y{y}{};
        double product() const;
    private:
        double _x;
        double _y;
};