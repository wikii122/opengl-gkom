#include <memory>

namespace gkom
{
	namespace dragonfly
	{
		class Head
		{
		public:
			Head();
			void display(long time);
		private:
			class Eye
			{
			public:
				Eye();
				void display(long time);
			};
			Eye left, right;
		};

		class Body
		{
		public:
			Body();
			void display();
		private:
			class Legs
			{
			public:
				Legs();
				void display(long time);
			};
		};

		class Tail
		{
		public:
			Tail();
			void display(long time);
		};

		class Wings
		{
		public:
			Wings();
			void display(long time);
		private:
			class Wing
			{
			public:
				Wing();
				void display(long time);
			};
			Wing left, right;
		};
	};
};