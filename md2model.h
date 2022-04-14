#pragma once
#include <vector>
#include <GL/glut.h>

#include "vec3f.h"

struct MD2Vertex {
	Vec3f pos;
	Vec3f normal;
};

struct MD2Frame {
	char name[16];
	MD2Vertex* vertices;
};

struct MD2TexCoord {
	float texCoordX;
	float texCoordY;
};

struct MD2Triangle {
	int vertices[3];  //The indices of the vertices in this triangle
	int texCoords[3]; //The indices of the texture coordinates of the triangle
};

class MD2Model {
	private:
		MD2Frame* frames;
		int numFrames;
		MD2TexCoord* texCoords;
		MD2Triangle* triangles;
		int numTriangles;
		std::vector<GLuint> textureIds;
		
		int startFrame; //The first frame of the current animation
		int endFrame;   //The last frame of the current animation
		
		MD2Model();
	public:
		~MD2Model();
		
		//Switches to the given animation
		void setAnimation(const char* name);
		/* Draws the state of the animated model at the specified time in the
		 * animation.  A time of i, integer i, indicates the beginning of the
		 * animation, and a time of i + 0.5 indicates halfway through the
		 * animation.  textureNum is the index of the texture that is used when
		 * drawing the model.
		 */
		void draw(int textureNum, float time);
		
		//Loads an MD2Model from the specified file, loading texture images from
		//the indicated files.  Returns NULL if there was an error loading it.
		static MD2Model* load(const char* filename,
							  std::vector<const char*> textureFilenames);
};
