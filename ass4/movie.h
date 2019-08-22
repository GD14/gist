#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>
using namespace std;

class Movie {
public:
		// constructor for the movie object
		// initialize movie object according to its type
		Movie(string title, string director, 
			string mainActor, string release, int stock);

		virtual ~Movie();

		// getting the title of the movie
		virtual string getTitle();


		// return movie title as a string
		// getting the name of the director
		virtual string getDirector();

		// getting the release date of the movie,
		// month if available, then movie
		// returns int value of release date
		virtual string getRelease();

		// gets name of major actor
		virtual string getActor();

		// gets stock of movie
		virtual string getStock();

		//-1 stock of the movie
		virtual bool borrowAMovie();

		//+1 stock of the movie
		virtual void returnAMovie();

private:
		// the title of the movie
		string title;

		// the main director of the movie
		string director;

		// the year the movie was released, includes month 
		string release;

		// how many of this movie are in stock
		int stock;

		string majorActor;
};

#endif
