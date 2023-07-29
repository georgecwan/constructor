#ifndef TILE_H
#define TILE_H

#include "../common/forward.h"
#include "../common/resource.h"
#include "abstracttile.h"

class Tile final : public AbstractTile {
  private:
    int tileNumber;
    int tileValue;
    Resource resource;
    std::vector<Vertex*> neighbouringVertices;
    std::vector<Edge*> neighbouringEdges;

  public:
    Tile(int, int, Resource);
    ~Tile();

    void addNeighbouringVertex(Vertex*) override;

    int getTileNumber() const override;
    int getTileValue() const override;
    Resource getResource() const override;
    void giveResourcesToBuilders() const override;

    bool hasGeese() const override;
};

#endif
