from PIL import Image, ImageOps


class MainProcess:
    def __init__(self, image_file):
        self.image_file = image_file
        self.image = Image.open(image_file)

        self._black_and_white()
        self._grey_scale()
        self._inverted_color()

    def _black_and_white(self):
        black_and_white_image = self.image.convert('1')
        black_and_white_image.save('black_and_white_' + self.image_file)

    def _grey_scale(self):
        gray_image = ImageOps.grayscale(self.image)
        gray_image.save('gray_scale_' + self.image_file)

    def _inverted_color(self):
        inverted_image = ImageOps.invert(self.image)
        inverted_image.save('inverted_' + self.image_file)


if __name__ == '__main__':
    image_file = "sample_640×426.bmp"

    imageProcess = MainProcess(image_file)

