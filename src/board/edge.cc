#include "edge.h"
#include "../game/builder.h"
#include "../structures/residence.h"
#include "../structures/road.h"
#include "vertex.h"

Edge::Edge(int edgeNumber) : edgeNumber{edgeNumber}, road{nullptr} {}
Edge::~Edge() {}

bool Edge::operator==(const Edge& other) const {
    return edgeNumber == other.edgeNumber && road == other.road && neighbouringTiles == other.neighbouringTiles &&
           neighbouringVertices == other.neighbouringVertices;
}

void Edge::addNeighbouringTile(AbstractTile* tile) {
    neighbouringTiles.emplace_back(tile);
}

void Edge::addNeighbouringVertex(Vertex* vertex) {
    neighbouringVertices.emplace_back(vertex);
}

int Edge::getEdgeNumber() const {
    return edgeNumber;
}

std::shared_ptr<Road> Edge::getRoad() const {
    return road;
}

std::vector<Vertex*> Edge::getNeighbouringVertices() const {
    return neighbouringVertices;
}

bool Edge::canBuildRoad(Builder& builder) const {
    if (road != nullptr) {
        // Road already exists!
        return false;
    }

    for (Vertex* vertex : neighbouringVertices) {
        // Vertex has residence owned by the builder
        if (vertex->getResidence() != nullptr && vertex->getResidence()->getOwner() == builder) {
            return true;
        }

        // Vertex is connected to a road owned by the builder
        for (Edge* edge : vertex->getNeighbouringEdges()) {
            if (edge->getRoad() != nullptr && edge->getRoad()->getOwner() == builder) {
                return true;
            }
        }
    }

    // No adjacent road or residence!
    return false;
}

void Edge::buildRoad(std::shared_ptr<Road> road) {
    this->road = road;
}