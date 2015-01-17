#include <memory>

namespace gkom
{
	namespace dragonfly
	{
		enum Side
		{
			Left,
			Right
		};
		class Head
		{
		public:
			Head();
			void draw(long time);
		private:
			void draw_object(long time);
			class Eye
			{
				Side side;
			public:
				Eye(Side);
				void draw();
			};
			Eye left, right;
		};

		class Body
		{
		public:
			void draw(long time);
		private:
			class Legs
			{
			public:
				void draw(long time);
			};
			Legs legs;
		};

		class Tail
		{
		public:
			void draw(long time);
		};

		class Wings
		{
		public:
			Wings();
			void draw(long time);
		private:
			class Wing
			{
				Side side;
			public:
				Wing(Side);
				void draw(long time);
			};
			Wing left, right;
		};
	};
};