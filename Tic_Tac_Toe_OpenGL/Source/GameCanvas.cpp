
#include <GameCanvas.h>
#include <ViewportModes.h>

/**
* \brief Destructor
*/
GameCanvas::~GameCanvas() { /* nothing to be cleared */ }

/**
* \brief Constructor
*/
GameCanvas::GameCanvas()
{
	_viewportMode = ViewPortMode::Quadruple;
}

/**
* \brief Receive window display events
*/
void GameCanvas::display()
{
	if (_viewportMode == ViewPortMode::Quadruple)
	{
		if (_blockContainer.empty())
		{
			auto x = 1;
			auto y = 1;
			auto xSteps = _width / ViewPortMode::Quadruple;
			auto ySteps = _height / ViewPortMode::Quadruple;
			auto width = xSteps - 1;
			auto height = ySteps - 1;

			for (auto h = 0; h < ViewPortMode::Quadruple; ++h)
			{
				x = 1;
				for (auto w = 0; w < ViewPortMode::Quadruple; ++w)
				{
					_blockContainer.push_back(Block(Viewport(x, y, width, height), MarkerType::None));
					x += xSteps;
				}
				y += ySteps;
			}
		}

		for (auto const& block : _blockContainer)
		{
			glViewport(block.viewport.x, block.viewport.y, block.viewport.width, block.viewport.height);
			gluOrtho2D(0, block.viewport.width, 0, block.viewport.height);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();

			drawShape(block.markerType, block.viewport.width, block.viewport.height);
		}
	}

	swapBuffers();
}

/**
* \brief Receive window resize events
*/
void GameCanvas::reshape(GLuint width, GLuint height)
{
	_width = width;
	_height = height;
	glViewport(0, 0, _width, _height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

/**
* \brief Draw shapes using given marker type
*/
void GameCanvas::drawShape(MarkerType markerType, int width, int height) const
{
	// draw white block
	{
		glBegin(GL_LINES);
		glColor3f(1.0f, 0.27f, 0.0f);
		glVertex2f(0, 0);
		glVertex2f(width, 0);
		glVertex2f(width, 0);
		glVertex2f(width, height);
		glVertex2f(width, height);
		glVertex2f(0, height);
		glVertex2f(0, 0);
		glEnd();
	}

	if (markerType == MarkerType::None)
		return;

	// draw circle
	if (markerType == MarkerType::Cirlce)
	{
		GLint cx = width/2;
		GLint cy = height/2;
		GLint radius = fmin(width, height)/3;
		static const int numSlices = 72;
		static const GLfloat deltaAngle = 2.0f * std::atan2f(0.0f, -1.0f) / numSlices;
		glColor3ub(0, 127, 0);
		glBegin(GL_LINE_LOOP);
			GLfloat angle = 0.0f;
			for (int i = 0; i < numSlices; ++i, angle += deltaAngle) 
				glVertex2f(cx + 0.5f + radius * std::cosf(angle), cy + 0.5f + radius * std::sinf(angle));
		glEnd();
	}
	else 
	if (markerType == MarkerType::Cross)
	{
		GLint margin = fmin(width, height) / 4;
		glColor3ub(127, 127, 0);
		glBegin(GL_LINES);
			glVertex2f(margin, margin);
			glVertex2f(width-margin, height-margin);
			glVertex2f(margin, height - margin);
			glVertex2f(width - margin, margin);
		glEnd();
	}
}

/**
* \brief Receive mouse events
*/
void GameCanvas::onMouseButton(int button, int state, int x, int y)
{
	// handle mouse events
}

/**
* \brief clear the canvas
*/
void GameCanvas::clear()
{
	for (auto &block : _blockContainer)
		block.markerType = MarkerType::None;
}

/**
* \brief select a canvas from vector of blocks using given index
*/
void GameCanvas::selectBlock(int index, MarkerType type)
{
	auto size = _blockContainer.size();
	if (size <= 0) return;

	if (index < 1 || index > size)
		return;

	_blockContainer[index-1].markerType = type;

	refresh();
}

/**
* \brief Check whether given index block is available to select
*/
bool GameCanvas::isBlockAvailable(int index)
{
	auto size = _blockContainer.size();
	if (size <= 0) return false;

	if (index < 1 || index > size)
		return false;

	return _blockContainer[index - 1].markerType == MarkerType::None;
}

/**
* \brief check for winner
*/
MarkerType GameCanvas::whoIsWinner()
{
	if (_blockContainer[0].markerType == _blockContainer[1].markerType && _blockContainer[1].markerType == _blockContainer[2].markerType)
		return _blockContainer[0].markerType;
	if (_blockContainer[3].markerType == _blockContainer[4].markerType && _blockContainer[4].markerType == _blockContainer[5].markerType)
		return _blockContainer[3].markerType;
	if (_blockContainer[6].markerType == _blockContainer[7].markerType && _blockContainer[7].markerType == _blockContainer[8].markerType)
		return _blockContainer[6].markerType;
	if (_blockContainer[0].markerType == _blockContainer[4].markerType && _blockContainer[4].markerType == _blockContainer[8].markerType)
		return _blockContainer[0].markerType;
	if (_blockContainer[2].markerType == _blockContainer[4].markerType && _blockContainer[4].markerType == _blockContainer[6].markerType)
		return _blockContainer[2].markerType;

	return MarkerType::None;
}
