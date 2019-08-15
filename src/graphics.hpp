// zgui by zxvnme (https://github.com/zxvnme) and all the community contributors

#define ZGUI_VERSION 2.0.0

#ifndef ZGUI_GRAPHICS_HPP
#define ZGUI_GRAPHICS_HPP

#include <cstddef>
#include <vector>

namespace zgui {

    class Color {
    public:
        Color() = default;
        explicit Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
        unsigned char r, g, b, a;
    };

    class Point {
    public:
        Point() = default;
        explicit Point(float x, float y) {
            this->x = x;
            this->y = y;
        }
        float x, y;
    };

    class Vertex {
    public:
        explicit Vertex(Point position, Point coordinates, Color color) {
            this->position = position;
            this->coordinates = coordinates;
            this->color = color;
        }
        Point position, coordinates;
        Color color;
    };

    enum class VertexTopology {
        LINE_LIST,
        LINE_STRIP,
        TRIANGLE_LIST,
        TRIANGLE_STRIP
    };

    class Graphics {
    protected:
        std::vector<Vertex> vertices;
        VertexTopology vertex_topology_;

    private:
        virtual void set_topology(VertexTopology vertex_topology);
        virtual void append_geometry(Vertex* vertices, size_t count);

    public:
        virtual void draw() = 0;
        virtual void reset() = 0;

        void draw_line(Point start, Point end, Color color);
        void fill_rect(Point position, Point size, Color color);
    };

}

#endif // ZGUI_GRAPHICS_HPP