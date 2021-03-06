#ifndef _GEOMTREE_H
#define _GEOMTREE_H

#include <vector>
#include "../Aabb.h"
#include "../matrix4x4.h"
#include "CollisionContact.h"

struct tri_t;

struct isect_t {
	// triIdx = -1 if no intersection
	int triIdx;
	float dist;
};

class BVHTree;
struct BVHNode;

class GeomTree {
public:
	GeomTree(int numVerts, int numTris, float *vertices, int *indices, unsigned int *triflags);
	~GeomTree();
	const Aabb &GetAabb() const { return m_aabb; }
	// dir should be unit length,
	// isect.dist should be ray length
	// isect.triIdx should be -1 unless repeat calls with same isect_t
	void CollideEdgesWithTrisOf(const GeomTree *other, const matrix4x4d &transTo, void (*callback)(CollisionContact*)) const;
	void TraceRay(const vector3f &start, const vector3f &dir, isect_t *isect) const;
	void TraceRay(const BVHNode *startNode, const vector3f &a_origin, const vector3f &a_dir, isect_t *isect) const;
	void TraceCoherentRays(int numRays, const vector3f &a_origin, const vector3f *a_dirs, isect_t *isects) const;
	void TraceCoherentRays(const BVHNode *startNode, int numRays, const vector3f &a_origin, const vector3f *a_dirs, isect_t *isects) const;
	vector3f GetTriNormal(int triIdx) const;
	int GetTriFlag(int triIdx) const { return m_triFlags[triIdx]; }
	double GetRadius() const { return m_radius; }
	struct Edge {
		int v1i, v2i;
		float len;
		vector3f dir;
		// edge triFlag can be weird since edges may get merged and
		// intended flag lost
		int triFlag;
	};
	const Edge *GetEdges() const { return m_edges; }
	int GetNumEdges() const { return m_numEdges; }

	const int m_numVertices;
	const float *m_vertices;
	static int stats_rayTriIntersections;

	BVHTree *m_triTree;
	BVHTree *m_edgeTree;
private:
	void RayTriIntersect(int numRays, const vector3f &origin, const vector3f *dirs, int triIdx, isect_t *isects) const;

	double m_radius;
	Aabb m_aabb;

	int m_numEdges;
	Edge *m_edges;

	const int *m_indices;
	const unsigned int *m_triFlags;
};

#endif /* _GEOMTREE_H */
