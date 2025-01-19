#include <iostream>
#include <glm/glm.hpp>
#include <vector>
#include <cmath>

struct PointCharge {
    float charge; 
    glm::vec3 position;
};

// calculate electric field at a point
glm::vec3 calculateElectricField(glm::vec3 point, const std::vector<PointCharge>& charges) {
    glm::vec3 E(0.f, 0.f, 0.f);
    const float k = 8987551787.3681764f; // Coulomb's constant
    for (const auto& charge : charges) {
        glm::vec2 r = point - charge.position;
        float distanceSquared = r.x * r.x + r.y * r.y + 0.1f; // add 0.1f to prevent divison by 0
        float fieldMagnitude = k * charge.charge / distanceSquared;
        float distance = std::sqrt(distanceSquared);
        glm::vec2 field = (r / distance) * fieldMagnitude;
        E += field;
    }
    return E;
}



int main() {
    std::cout << "Hello, world!\n";
}
