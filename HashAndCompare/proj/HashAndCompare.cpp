#include "HashAndCompare.h"

//http://stackoverflow.com/questions/3536781/accessing-directories-in-c

using namespace std;

HashAndCompare::HashAndCompare( const char * filePath )
{
	m_filePath = filePath;
}
HashAndCompare::~HashAndCompare(){}

int HashAndCompare::listDir()
{
    struct dirent *entry;
    DIR *dp;

    dp = opendir(m_filePath);
    if (dp == NULL)
    {
        perror("opendir: Path does not exist or could not be read.");
        return -1;
    }

    while ((entry = readdir(dp)))
    {
		files.push_back(entry->d_name);
    }

    closedir(dp);
    return 0;
}

int HashAndCompare::hash( string key )
{
    int hashVal = 0;

    for( unsigned int i = 0; i < key.length( ); i++ )
    {
    	hashVal = 37 * hashVal + key[ i ];
    }

    return hashVal;
}

void HashAndCompare::parse()
{
	listDir();
	for (unsigned int i = 2; i < files.size(); i++)
	{
		string holdFile( files[i] );
		string path( m_filePath );
		string stringPath = path + "/" + holdFile;
		const char * charPath = stringPath.c_str();

		string holdLine;
	
		ifstream inFile( charPath );

		if ( inFile.is_open() )
		{
			while ( getline( inFile, holdLine, '\n') )
			{
				for ( unsigned int i = 0; i < holdLine.size(); i++ )
				{
					char a = holdLine.at(i);
					if ( ( a < 65 ) || ( a > 122 ) )
					{ 
						holdLine[i] = ' ';
					}
					if ( ( a < 97 ) && ( a > 90 ) )
					{ 
						holdLine[i] = ' ';
					}
					else if ( ( a < 91 ) && ( a > 64 ) )
					{
						a = a + 32;
						holdLine[i] = char(a);
					}
				}//end for <holdLine.size()

				stringstream splitLine( holdLine );
				string holdWord;
			

				while ( getline( splitLine, holdWord, ' ') )
				{
					bool wordFlag = false;
					for (unsigned int i = 0; i < holdWord.size(); i++)
					{
						if( ( holdWord.at(i) >= 97 ) || ( holdWord.at(i) <= 122 ) )
						{
							wordFlag = true;
						}
					}//end for
					if ( wordFlag==true )
					{

						if ( holdFile == "AnthonyAndCleo.txt")
						{AnthonyAndCleo.push_back(holdWord);}

						else if ( holdFile == "Hamlet.txt")
						{Hamlet.push_back(holdWord);}

						else if ( holdFile == "JuliusCaesar.txt")
						{JuliusCaesar.push_back(holdWord);}

						else if ( holdFile == "KingLear.txt")
						{KingLear.push_back(holdWord);}

						else if ( holdFile == "Macbeth.txt")
						{Macbeth.push_back(holdWord);}

						else if ( holdFile == "Othello.txt")
						{Othello.push_back(holdWord);}

						else if ( holdFile == "Pericles.txt")
						{Pericles.push_back(holdWord);}

						else if ( holdFile == "RomeoJuliet.txt")
						{RomeoJuliet.push_back(holdWord);}

						else if ( holdFile == "Tempest.txt")
						{Tempest.push_back(holdWord);}

						else if ( holdFile == "TitusAndronicus.txt")
						{TitusAndronicus.push_back(holdWord);}

					}	//end if flag		
				}// end while getline inside
		
			}//end while getline outside

		}//end if is_open()

		else
		{
			cerr<<"cannot open file"<<endl;
		}
		//hash

		//vector<string> hash_KingLear[KingLear.size()];



			if ( holdFile == "AnthonyAndCleo.txt")
			{
				vector<string> hash_AnthonyAndCleo[AnthonyAndCleo.size()];
				for (unsigned int i = 0; i < AnthonyAndCleo.size(); i++ )
				{
		
					int hashVal = ( hash(AnthonyAndCleo[i]) % AnthonyAndCleo.size() );
					hash_AnthonyAndCleo[hashVal].push_back( AnthonyAndCleo[i] );

				}

			}
					
			else if ( holdFile == "Hamlet.txt")
			{
				vector<string> hash_Hamlet[Hamlet.size()];
				for (unsigned int i = 0; i < Hamlet.size(); i++ )
				{
					int hashVal = ( hash(Hamlet[i]) % Hamlet.size() );
					hash_Hamlet[hashVal].push_back(Hamlet[i] );
				}
			}
					
			else if ( holdFile == "JuliusCaesar.txt")
			{
				vector<string> hash_JuliusCaesar[JuliusCaesar.size()];
				for (unsigned int i = 0; i < JuliusCaesar.size(); i++ )
				{
					int hashVal = ( hash(JuliusCaesar[i]) % JuliusCaesar.size() );
					hash_JuliusCaesar[hashVal].push_back( JuliusCaesar[i] );
				}
			}
		
			else if ( holdFile == "KingLear.txt")
			{
				vector<string> hash_KingLear[KingLear.size()];
				for (unsigned int i = 0; i < KingLear.size(); i++ )
				{
					int hashVal = ( hash(KingLear[i]) % KingLear.size() );
					hash_KingLear[hashVal].push_back( KingLear[i] );
				}
			}
					
			else if ( holdFile == "Macbeth.txt")
			{
				vector<string> hash_Macbeth[Macbeth.size()];
				for (unsigned int i = 0; i < Macbeth.size(); i++ )
				{
					int hashVal = ( hash(Macbeth[i]) % Macbeth.size() );
					hash_Macbeth[hashVal].push_back( Macbeth[i] );
				}
			}
					
			else if ( holdFile == "Othello.txt")
			{
				vector<string> hash_Othello[Othello.size()];

				for (unsigned int i = 0; i < Othello.size(); i++ )
				{	
					int hashVal = ( hash(Othello[i]) % Othello.size() );
					hash_Othello[hashVal].push_back( Othello[i] );
				}
			}
					
			else if ( holdFile == "Pericles.txt")
			{
				vector<string> hash_Pericles[Pericles.size()];
				for (unsigned int i = 0; i < Pericles.size(); i++ )
				{
					int hashVal = ( hash(Pericles[i]) % Pericles.size() );
					hash_Pericles[hashVal].push_back( Pericles[i] );
				}
			}

			else if ( holdFile == "RomeoJuliet.txt")
			{
				vector<string> hash_RomeoJuliet[RomeoJuliet.size()];
				for (unsigned int i = 0; i < RomeoJuliet.size(); i++ )
				{
					int hashVal = ( hash(RomeoJuliet[i]) % RomeoJuliet.size() );
					hash_RomeoJuliet[hashVal].push_back( RomeoJuliet[i] );
				}
			}
					
			else if ( holdFile == "Tempest.txt")
			{
				vector<string> hash_Tempest[Tempest.size()];
				for (unsigned int i = 0; i < Tempest.size(); i++ )
				{	
					int hashVal = ( hash(Tempest[i]) % Tempest.size() );
					hash_Tempest[hashVal].push_back( Tempest[i] );
				}

			}
			else if ( holdFile == "TitusAndronicus.txt")
			{
				vector<string> hash_TitusAndronicus[TitusAndronicus.size()];
				for (unsigned int i = 0; i < TitusAndronicus.size(); i++ )
				{
					int hashVal = ( hash(TitusAndronicus[i]) % TitusAndronicus.size() );
					hash_TitusAndronicus[hashVal].push_back( TitusAndronicus[i] );

				}

			}
	}//end for file.size()



	//prints hashtable
	//****to be removed

			cout<<"testing 1 2: "<<sizeof(hash_AnthonyAndCleo)<<endl;
	for (unsigned int i = 0; i < sizeof(hash_AnthonyAndCleo); i++)
	{
		cout<<"at vector "<<i<<endl;
		if ( hash_AnthonyAndCleo[i].size() > 0 )
		{
		for (unsigned int j = 0; j < hash_AnthonyAndCleo[i].size(); j++)
		{
			cout<<"x"<<endl;
			cout<<hash_AnthonyAndCleo[i][j]<<" ";
		}
		cout<<endl;
	}
	else{cout<<"nothing"<<endl;}
	}		
}//end parse
