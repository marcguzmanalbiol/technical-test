from PIL import Image, ImageOps


class MainProcess:
    def __init__(self, file):
        """
        Process the image given by the argument file and saves 3 different versions: black and white, grey-scale and
        inverted colored one. Uses the PIL library to do all this operations.
        Args:
            file: string corresponding of the location of the image we want to process.
        """
        self.image_file = file
        self.image = Image.open(image_file)

        self._black_and_white()
        self._grey_scale()
        self._inverted_color()

    def _black_and_white(self):
        """
        This function creates and saves a black and white version of the original image.
        Returns: Nothing, but saves in the current directory an image called 'black_and_white_' + name of the original
        image.
        """
        black_and_white_image = self.image.convert('1')
        black_and_white_image.save('black_and_white_' + self.image_file)

    def _grey_scale(self):
        """
        This function creates and saves a grey-scale version of the original image.
        Returns: Nothing, but saves in the current directory an image called 'grey_scale_' + name of the original
        image.
        """
        gray_image = ImageOps.grayscale(self.image)
        gray_image.save('gray_scale_' + self.image_file)

    def _inverted_color(self):
        """
        This function creates and saves a inverted color version of the original image.
        Returns: Nothing, but saves in the current directory an image called 'inverted_' + name of the original
        image.
        """
        inverted_image = ImageOps.invert(self.image)
        inverted_image.save('inverted_' + self.image_file)


if __name__ == '__main__':
    image_file = "sample_640×426.bmp"

    imageProcess = MainProcess(image_file)
