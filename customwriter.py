

def get_arguments():
	import argparse
	parser = argparse.ArgumentParser()

	parser.add_argument('src', help='Source file of lambdas definitions')
	parser.add_argument('dest', help='Destination file for generated code')

	return parser.parse_args()


def main():
	args = get_arguments()
	print ('start')

if __name__ == '__main__':
	main()

